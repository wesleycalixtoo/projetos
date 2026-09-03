namespace ConversorTemperatura
{
    partial class Form1
    {
        private System.ComponentModel.IContainer components = null;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        private Label lblTitulo;
        private Label lblValor;
        private TextBox txtValor;
        private Label lblOperacao;
        private ComboBox cmbOperacao;
        private Button btnConverter;
        private Button btnLimpar;
        private Label lblResultadoTitulo;
        private Label lblResultado;

        #region Windows Form Designer generated code

        private void InitializeComponent()
        {
            this.lblTitulo = new Label();
            this.lblValor = new Label();
            this.txtValor = new TextBox();
            this.lblOperacao = new Label();
            this.cmbOperacao = new ComboBox();
            this.btnConverter = new Button();
            this.btnLimpar = new Button();
            this.lblResultadoTitulo = new Label();
            this.lblResultado = new Label();
            this.SuspendLayout();

            // lblTitulo
            this.lblTitulo.AutoSize = true;
            this.lblTitulo.Font = new Font("Segoe UI", 14F, FontStyle.Bold);
            this.lblTitulo.Location = new Point(20, 15);
            this.lblTitulo.Text = "Conversor de Temperatura";

            // lblValor
            this.lblValor.AutoSize = true;
            this.lblValor.Location = new Point(20, 65);
            this.lblValor.Text = "Valor a converter:";

            // txtValor
            this.txtValor.Location = new Point(160, 62);
            this.txtValor.Size = new Size(180, 23);

            // lblOperacao
            this.lblOperacao.AutoSize = true;
            this.lblOperacao.Location = new Point(20, 105);
            this.lblOperacao.Text = "Operação:";

            // cmbOperacao
            this.cmbOperacao.DropDownStyle = ComboBoxStyle.DropDownList;
            this.cmbOperacao.Location = new Point(160, 102);
            this.cmbOperacao.Size = new Size(250, 23);
            this.cmbOperacao.Items.AddRange(new object[] {
                "Kelvin -> Fahrenheit",
                "Fahrenheit -> Celsius",
                "Celsius -> Kelvin",
                "Fahrenheit -> Kelvin"});
            this.cmbOperacao.SelectedIndex = 0;

            // btnConverter
            this.btnConverter.Location = new Point(160, 145);
            this.btnConverter.Size = new Size(110, 32);
            this.btnConverter.Text = "Converter";
            this.btnConverter.UseVisualStyleBackColor = true;
            this.btnConverter.Click += new EventHandler(this.btnConverter_Click);

            // btnLimpar
            this.btnLimpar.Location = new Point(300, 145);
            this.btnLimpar.Size = new Size(110, 32);
            this.btnLimpar.Text = "Limpar";
            this.btnLimpar.UseVisualStyleBackColor = true;
            this.btnLimpar.Click += new EventHandler(this.btnLimpar_Click);

            // lblResultadoTitulo
            this.lblResultadoTitulo.AutoSize = true;
            this.lblResultadoTitulo.Location = new Point(20, 200);
            this.lblResultadoTitulo.Text = "Resultado:";

            // lblResultado
            this.lblResultado.AutoSize = true;
            this.lblResultado.Font = new Font("Segoe UI", 12F, FontStyle.Bold);
            this.lblResultado.ForeColor = Color.DarkBlue;
            this.lblResultado.Location = new Point(160, 197);
            this.lblResultado.Text = "-";

            // Form1
            this.AutoScaleDimensions = new SizeF(7F, 15F);
            this.AutoScaleMode = AutoScaleMode.Font;
            this.ClientSize = new Size(450, 250);
            this.Controls.Add(this.lblTitulo);
            this.Controls.Add(this.lblValor);
            this.Controls.Add(this.txtValor);
            this.Controls.Add(this.lblOperacao);
            this.Controls.Add(this.cmbOperacao);
            this.Controls.Add(this.btnConverter);
            this.Controls.Add(this.btnLimpar);
            this.Controls.Add(this.lblResultadoTitulo);
            this.Controls.Add(this.lblResultado);
            this.FormBorderStyle = FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.StartPosition = FormStartPosition.CenterScreen;
            this.Text = "Conversor de Temperatura";
            this.ResumeLayout(false);
            this.PerformLayout();
        }

        #endregion
    }
}
