# Cio2
![](https://github.com/dlrds/Cio2/blob/master/Imagens/logo%20(2).png)
Projeto final para a disciplina de Circuitos Lógicos


## Objetivos do Projeto
* Reutilizar água desperdiçada dos ar condicionados da instituição;
* Exibir valores (temperatura, umidade do ar e quantidade de irrigações diárias) periodicamente;
* Monitorar o desenvolvimento de plantas por meio de um sistema de irrigação.


## Introdução
Algo que é trivial de todo indivíduo saber é que a crise hídrica mundial é uma situação existente, e que o mal uso daágua pode agravar bastante a situação. Dentre as enormes formas de desperdício de água, está no uso do ar-condicionado,onde, indiretamente, é desperdiçada uma grande quantidade de água que é liberada por tal.


No caso de lugares com grandes estruturas, como no caso das universidades, esse desperdício tende a ser muito maior.Pensando nisso, decidimos reutilizar a água desperdicidada dos ares-condicionados do Ci (Centro Informática) da UniversidadeFederal da Paraíba, com o propósito de irrigar plantas que serão cultivadas na instituição, quando estas necessitarem de tal irrigação.


## Metodologia

Nosso trabalho foi dividido em quatro frentes: a criação do ambiente projetado em maquete, a constução do sistemade irrigação, a montagem do relógio digital e a mostra da temperatura e da umidade. Utilizamos uma maquete baseada naestrutura do Ci para melhor entendimento da aplicação do projeto. A montagem do prédio principal feito de caixa de papelão,acriílico e plástico.

O relógio foi utilizado o Real Time Clock RTC DS3231, módulo utilizado como memória, 4 codificadores de binário paraa montagem dos displays de sete segmentos e os próprios displays. Os valores de temperatura e umidade foram adquiridosa partir do sensor “DHT11” , sendo estes expostos por meio de displays de sete segmentos. Para a montagem do sistema deirrigação, foi projetado um sensor de umidade do solo caseiro e um clock com o CI555, estes utilizados no flip-flop tipo D que irácontrolar uma válvula solenóide, que permite ou não a passagem da água.


## Descrição do projeto

Serão exibidas em displays de sete segmentos a temperatura e a umidade do ar. O momento em que a água será liberadapara essas plantas será feito a partir do monitoramento de um sensor de umidade do solo caseiro. E ainda, os sistemas serãosimulados e representados com o auxílio de uma maquete.


## Execução do projeto, testes e resultados

## Circuito 1
![](https://github.com/dlrds/Cio2/blob/master/Imagens/Circuito.jpeg)

## Circuito 2
![](https://github.com/dlrds/Cio2/blob/master/Imagens/Circuito2.jpeg)

```javascript
    var init = "Olá, mundo!";
    alert(init);
    ````
## Referências
