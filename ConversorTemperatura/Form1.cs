using System;
using System.Globalization;
using System.Windows.Forms;

namespace ConversorTemperatura
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnConverter_Click(object? sender, EventArgs e)
        {
            // Aceita tanto "," quanto "." como separador decimal
            string texto = txtValor.Text.Trim().Replace(",", ".");

            if (!double.TryParse(texto, NumberStyles.Float, CultureInfo.InvariantCulture, out double valor))
            {
                MessageBox.Show("Digite um valor numérico válido.", "Entrada inválida",
                    MessageBoxButtons.OK, MessageBoxIcon.Warning);
                lblResultado.Text = "-";
                return;
            }

            double resultado = 0;
            string unidadeSaida = "";

            switch (cmbOperacao.SelectedIndex)
            {
                case 0: // Kelvin para Fahrenheit
                    resultado = (valor - 273.15) * 1.8 + 32;
                    unidadeSaida = "°F";
                    break;

                case 1: // Fahrenheit para Celsius
                    resultado = (valor - 32) / 1.8;
                    unidadeSaida = "°C";
                    break;

                case 2: // Celsius para Kelvin
                    resultado = valor + 273.15;
                    unidadeSaida = "K";
                    break;

                case 3: // Fahrenheit para Kelvin
                    resultado = (valor - 32) * 5.0 / 9.0 + 273.15;
                    unidadeSaida = "K";
                    break;
            }

            lblResultado.Text = $"{resultado:F2} {unidadeSaida}";
        }

        private void btnLimpar_Click(object? sender, EventArgs e)
        {
            txtValor.Clear();
            lblResultado.Text = "-";
            cmbOperacao.SelectedIndex = 0;
            txtValor.Focus();
        }
    }
}
