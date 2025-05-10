package com.example.hesapmakinesi

import android.os.Bundle
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

class MainActivity : AppCompatActivity() {

    private lateinit var textViewInput: TextView
    private var currentInput = ""
    private var firstNumber = 0.0
    private var secondNumber = 0.0
    private var currentOperator = ""

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        textViewInput = findViewById(R.id.textViewInput)

        val button0: Button = findViewById(R.id.button0)
        val button1: Button = findViewById(R.id.button1)
        val button2: Button = findViewById(R.id.button2)
        val button3: Button = findViewById(R.id.button3)
        val button4: Button = findViewById(R.id.button4)
        val button5: Button = findViewById(R.id.button5)
        val button6: Button = findViewById(R.id.button6)
        val button7: Button = findViewById(R.id.button7)
        val button8: Button = findViewById(R.id.button8)
        val button9: Button = findViewById(R.id.button9)
        val buttonDot: Button = findViewById(R.id.buttonDot)
        val buttonPlus: Button = findViewById(R.id.buttonPlus)
        val buttonMinus: Button = findViewById(R.id.buttonMinus)
        val buttonMultiply: Button = findViewById(R.id.buttonMultiply)
        val buttonDivide: Button = findViewById(R.id.buttonDivide)
        val buttonClear: Button = findViewById(R.id.buttonClear)
        val buttonEquals: Button = findViewById(R.id.buttonEquals)

        // Butonlara tıklama olaylarını ekleyelim
        button0.setOnClickListener { appendNumber("0") }
        button1.setOnClickListener { appendNumber("1") }
        button2.setOnClickListener { appendNumber("2") }
        button3.setOnClickListener { appendNumber("3") }
        button4.setOnClickListener { appendNumber("4") }
        button5.setOnClickListener { appendNumber("5") }
        button6.setOnClickListener { appendNumber("6") }
        button7.setOnClickListener { appendNumber("7") }
        button8.setOnClickListener { appendNumber("8") }
        button9.setOnClickListener { appendNumber("9") }
        buttonDot.setOnClickListener { appendNumber(".") }

        // İşlem butonları
        buttonPlus.setOnClickListener { setOperator("+") }
        buttonMinus.setOnClickListener { setOperator("-") }
        buttonMultiply.setOnClickListener { setOperator("×") }
        buttonDivide.setOnClickListener { setOperator("÷") }

        // Temizleme butonu
        buttonClear.setOnClickListener { clearInput() }

        // Eşittir butonu
        buttonEquals.setOnClickListener { calculateResult() }
    }

    // Sayı ekleme fonksiyonu
    private fun appendNumber(number: String) {
        currentInput += number
        textViewInput.text = currentInput
    }

    // İşlem set etme fonksiyonu
    private fun setOperator(operator: String) {
        if (currentInput.isNotEmpty()) {
            firstNumber = currentInput.toDouble()
            currentInput = ""
            currentOperator = operator
        }
    }

    // Temizleme fonksiyonu
    private fun clearInput() {
        currentInput = ""
        textViewInput.text = "0"
    }

    // Sonuç hesaplama fonksiyonu
    private fun calculateResult() {
        if (currentInput.isNotEmpty()) {
            secondNumber = currentInput.toDouble()

            when (currentOperator) {
                "+" -> currentInput = (firstNumber + secondNumber).toString()
                "-" -> currentInput = (firstNumber - secondNumber).toString()
                "×" -> currentInput = (firstNumber * secondNumber).toString()
                "÷" -> {
                    if (secondNumber != 0.0) {
                        currentInput = (firstNumber / secondNumber).toString()
                    } else {
                        currentInput = "Error"
                    }
                }
            }

            textViewInput.text = currentInput
            currentOperator = ""
            firstNumber = 0.0
        }
    }
}
