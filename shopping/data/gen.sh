./gen 1 > shopping1.in
./gen 1 > shopping2.in
./gen 1 > shopping3.in
./gen_sub2 10 > shopping4.in
./gen_sub2 10 > shopping5.in
./gen_sub2 10 > shopping6.in
./gen 10 > shopping7.in
./gen 10 > shopping8.in
./gen 10 > shopping9.in
./gen 10 > shopping10.in
for((i=1;i<=10;i++));
do
./std < shopping$(expr $i).in > shopping$(expr $i).ans
done
