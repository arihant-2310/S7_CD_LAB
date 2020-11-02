                 SHIFT REDUCE PARSER 

 GRAMMER<br>

 E->E+E <br>
 E->E*E<br>
 E->a<br>
 enter the input symbol:        a+a+a <br>

         stack implementation table
 <pre>
 stack           input symbol            action <br>
________                ____________            ____________<br>

 $              a+a+a$                  --  <br>
 $a              +a+a$                  shifta <br>
 $E              +a+a$                  E->a<br>
 $E+              a+a$                  shift+<br>
 $E+a              +a$                  shifta<br>
 $E+E              +a$                  E->a<br>
 $E                +a$                  E->E+E<br>
 $E+                a$                  shift+<br>
 $E+a                $                  shifta<br>
 $E+E                $                  E->a<br>
 $E                  $                  E->E+E<br>
 $E                  $                  ACCEPT<br>
 </pre>
