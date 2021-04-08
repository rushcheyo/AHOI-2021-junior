for((i=1;i<=5;i++));
do
python3 ./gen.py 9 > sort$(expr $i).in
done
for((i=6;i<=10;i++));
do
python3 ./gen.py 16 > sort$(expr $i).in
done
for((i=11;i<=14;i++));
do
python3 ./gen.py 50 > sort$(expr $i).in
done
python3 ./gen_w1.py 471 > sort15.in
python3 ./gen_w1.py 213 > sort16.in
python3 ./gen_w1.py 368 > sort17.in
for((i=18;i<=20;i++));
do
python3 ./gen.py 500 > sort$(expr $i).in
done
for((i=1;i<=20;i++));
do
./std < sort$(expr $i).in > sort$(expr $i).ans
done
