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

## Relógio

# Código do relógio
```c
    #include <stdio.h>
``` 

### Circuito do relógio
![](https://github.com/dlrds/Cio2/blob/master/Imagens/Circuito.jpeg)


## Circuito 2
![](https://github.com/dlrds/Cio2/blob/master/Imagens/Circuito2.jpeg)



# Código do DHT11
```c
    #include <stdio.h>
``` 
# Referências
 * MEIRA, Marcos Cavalcante; NETO, José Diniz; LIMA, Cláudio Galeno Queiroga Oliveira; JÚNIOR, Walmeran José Trindade;DIAS, José Artur Alves; BARBACENA, Ilton Luiz. Estudo e desenvolvimento de um circuito de um relógio digital utilizandofundamentalmente conhecimentos em circuitos lógicos. Circuitos lógicos, portas lógicas, relógio digital, Instituto Federalda Paraiba, 2012. Disponível em:http://propi.ifto.edu.br/ocs/index.php/connepi/vii/paper/viewFile/1076/2509. Acesso em: 9 ago. 2019.
 
 * SANTOS, Jean Carlos Fabiano dos. Sistema Inteligente de Automatização de Bombas de Irrigação por Temperatura eUmidade, Centro de Tecnologia e Urbanismo Departamento de Engenharia Elétrica, 17 nov. 2014. Disponível em:http://www.uel.br/ctu/deel/TCC/TCC2014-JeanCarlosFabianoSantos.pdf. Acesso em: 10 ago. 2019.
 
 * CAPUANO, Francisco Gabriel; IDOETA, Ivan Valeiji. Estudo e desenvolvimento de um circuito de um relógio digital utilizandofundamentalmente conhecimentos em circuitos lógicos. In: CAPUANO, Francisco Gabriel; IDOETA, Ivan Valeiji. ElementosDe Eletrônica Digital. 41. ed. São Paulo: érica, 2012. cap. Circuitos Combinacionais, p. 175-248. ISBN 978-85-7194-019-2.
