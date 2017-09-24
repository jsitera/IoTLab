# Hraní s LEDkami 
Hraní s LEDkami na IoT-clock platformě (kruhové spořádání ledek)

## Soubor IoT-clock-play-with-LEDs
Tento tutorial slouží k výuce polí a for cyklu. Doporučený postup je v malých krocích reprezentovaných jednotlivými rutinami.
Vždy odkomentujte jednu řádku v loop() (aby byla odkomentována jen jedna)
1. singleRotating1 - vysvětlení co je to pole, index, jak se do něj přiřazuje, vysvětlení jednoduchého for cyklu,
   vyzkoušet a zamyslet se, co s tím, aby obíhala dioda (a zhasínala)
2. singleRotating2 - jednoduché zobraz-počkej-zhasni
3. fourRotating - netřeba zhasínat, stačí vždy začít na čistém stole, potřeba normalizace do rozsahu 0-59, řešení 
   přes jednoduchou úvahu a if (řešení přes modulo až příště)
4. colorWorm - jiné uspořádání diod, hraní s barvou a časováním
5. worm - použití vlastností knihovny - snižování jasu o procenta (0-255), vytvoření "ocasu"

## soubor twoWorms
Výuka do-while cyklu - dva protiběžné cykly pro indexy x a y - dvě žížaly proti sobě.
Použití sčítání barev (vyzkoušejte bez toho). Operátor += a operátory ++ a --.
