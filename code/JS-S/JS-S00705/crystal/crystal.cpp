#include <bits/stdc++.h>
using namespace std;

int n;
long long m, a[500005], bx;

bool B = 1;

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (i == 1)continue;
		if (i == 2)bx = a[i] - a[i - 1];
		if (a[i]-a[i-1]!=bx)B=0;
	}
	if (B)
	{
		int cnt = 0;
		while (bx * cnt <= m)
		{
			m-=bx*cnt;
			cnt++;
		}
		cout << cnt << endl;
		return 0;
	}
	sort(a + 1, a + n + 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i == 1)
		{
			cnt++;
			continue;
		}
		if ((i - 1) * (a[i] - a[i - 1]) > m) break;
		cnt++;
		m -= (i - 1) * (a[i] - a[i - 1]);
 	}
 	cout << cnt << endl;
	return 0;
}
/*
#include <bit>
#include <bits/a.out.h>
#include <bits/algorithmfwd.h>
#include <bitset>
#include <bits/allocated_ptr.h>
#include <bits/allocator.h>
#include <bits/alloc_traits.h>
#include <bits/argp-ldbl.h>
#include <bits/atomic_base.h>
#include <bits/bits/atomic_futex.h>
#include <bits/atomic_lockfree_defines.h>
#include <bits/atomic_word.h>
#include <bits/auxv.h>
12323123213132312321312323123213123123123233123213213213123123123123213123213232323232323232323231313212312313
baka
sakuya is good

genshin start


ccf

luogu

delta force

3DFUP

.----1
..---2
...--3
....-4
.....5
-....6
--...7
---..8
----.9
-----0

qwerty123456mnbvcxz

freeopen
destruction 3, 2, 1

miku eat teto

114514

ZUN

ac
ak
rp
rp++
++rp

oi

ioi
noip
noi
wc


simple

touhou

+--+--+--






hyw









X X XXX






what do you want more than a happy endding?









<EZ> <HD> <IN> <AT>







<AT    @@@@@     @@@@@@     >
         @@@    @@@  @@@
         @@@    @@    @@
         @@@    @@    @@
         @@@     @@  @@
         @@@      @@@@
         @@@     @@  @@
         @@@    @@    @@
         @@@    @@    @@
         @@@    @@@  @@@
         @@@     @@@@@@






cout << "cout << "cout << "cout << "cout << "" << endl;" << endl;" << endl;" << endl;" << endl;
struct
{

}


freeeeeeeeeeeeeeeeeeeeeeeeeeeeopen

985 + 211
* 5
= 5980



6000-20=5980



\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/\sakuya/

+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--


UUZ is hungry

so UUZ want to eat anything like mashu,youmu,xi xing yao

someone open the O2 and I can't breath the O2!!!!!

cpp

exe

zi san xia qi bai li zhong, liang an lian shan, lue wu que chu,chong yan die zhang,ying tian bi ri, zi fei ting wu ye fen, bu jian xi yue
zhi yu xia shui xiang ling, yan su zu jue, huo wang ming ji xuan, you shi zhao fa bai di, mu zhi jiang ling, qi jian qian er bai li, bu yi ji ye
chun dong zhi shi, ze su tuan lv tan, hui qing dao ying, xuan quan pu bu, fei shu qi jian qing rong jun mao, liang duo qu wei
mei zhi qing chu shuang dan, lin han jian su, chang you gao yuan chang xiao, zhu yin qi yi, kong gu chuan xiang, ai zhuan jiu jue ,gu yu zhe ge yue, ba dong san xia wu xia chang, yuan ming san shen lei zhan chang

I want to play BA

sleep(114514)
zzz...zzzzzz...zzz...zzz...zzzzz...zzzzzzz...zzz...zzzzzzz...zzzz...zzzzzz....zzzzzz...zzzzzzzz...zzzzzzzzzzzzz...zzzzzz...zzzzz...zzzzzzz...zzzzzzzz...zzzzzzzzzzzzzzz...zzzzzzzzzz...zzzzzzzzzzzz...zzzzzz...zzzzzzzz....zzzzzzzzz....zzzzzzzzzz...zzzzzzzzz...zzzzzzzzz...zzzzzzzzzzzz.....zzzzzzzzzzzzzzzzzzzzzzzzzzz....zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz....zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz...zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz...zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz...zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz
I'm lazy to zzz to 114514

##################################################
##################################################
##################################################
##################################################
##################################################
##################################################
##################################################
##################################################
##################################################
##################################################
##################################################
##################################################
##################################################
##################################################
##################################################
##################################################
##################################################
##################################################
##################################################
##################################################

843BE656D4E1AB63


CCF

  @@@@@   @@@@@  @@@@@@
 @@@@@@  @@@@@@  @@@@@@
 @@      @@      @@
@@@     @@@      @@
@@      @@       @@@@@@
@@      @@       @@@@@@
@@@     @@@      @@
 @@      @@      @@
 @@@@@@  @@@@@@  @@
  @@@@@   @@@@@  @@


shan chuan zhi mei, gu lai gong tan, gao feng ru yun, qing liu jian di, liang an shi bi, wu se jiao hui, qing lin cui zhu, si shi ju bei, xiao wu jiang xie , yuan niao luan ming, xi ri yu tui, chen ling jing yue, shi shi yu jie zhi xian du, zi kang le yi lai, wei fu you neng yu qi qi zhe

*/

