🔊 ESP32 – Som de Queda e Explosão com Buzzer e LEDs

Este projeto utiliza um ESP32, um buzzer e dois LEDs para simular um efeito sonoro de queda seguido de explosão, com efeitos visuais sincronizados.

O som é gerado variando a frequência do buzzer, enquanto os LEDs piscam para simular impacto e explosão 💥.

📦 Componentes Utilizados

1× ESP32

1× Buzzer (preferencialmente passivo)

2× LEDs

Protoboard (opcional)

🔌 Ligações (Pinagem)
Componente	Pino ESP32
Buzzer (+)	GPIO 18
Buzzer (–)	GND
LED 1	GPIO 19 (com resistor)
LED 2	GPIO 21 (com resistor)
LEDs (–)	GND

⚙️ Funcionamento do Código

O programa executa continuamente dois efeitos principais:

1️⃣ Som de queda

O buzzer começa em uma frequência alta (1000 Hz)

A frequência vai diminuindo gradualmente até 100 Hz

Simula um apito descendente, como algo caindo

O LED 1 permanece aceso durante esse efeito

2️⃣ Explosão

O buzzer emite sons rápidos com frequências aleatórias

Os LEDs piscam alternadamente, criando um efeito de flash

Simula uma explosão ou impacto final

Após a explosão, o sistema aguarda um curto tempo e repete o efeito.

🧠 Lógica Principal do Código

tone() é usado para gerar som no buzzer

random() cria variação de frequência para o efeito de explosão

digitalWrite() controla os LEDs

delay() define o ritmo do som e dos efeitos visuais

⚠️ Observações Importantes

Em ESP32, a função tone() pode não funcionar perfeitamente em todas as versões

Para projetos mais avançados, recomenda-se usar PWM com ledcWriteTone()

O volume do buzzer pode variar conforme o modelo utilizado
