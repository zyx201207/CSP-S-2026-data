#include<bits/stdc++.h>
using namespace std;

int readint(){
	int k = 0,f = 1,c = getchar();
	for(;!isdigit(c);c = getchar()) if(c == '-') f = -1;
	for(;isdigit(c);c = getchar()) k = k * 10 + (c - '0');
	return k * f; 
}

int n,m,res;

int ans[300005];
int orirank[500005];

vector<int> desk;
bool on_desk[500005];


void play(int i){
	for(int ind = i;ind <= n;++ind){
		int op = orirank[ind];
		if(on_desk[op]){
			while(desk.back() != op){
				on_desk[desk.back()] = 0;
				desk.pop_back();
			}
		}
		else{
			on_desk[op] = 1;
			desk.push_back(op); 
		}
	}
	return;
}

void clear(){
	for(int i = 0;i < desk.size();++i) ++ans[desk[i]];
	desk.clear();
	memset(on_desk,0,sizeof(on_desk));
	return;
}

int main(){
	freopen("card.in ","r",stdin);
	freopen("card.out ","w",stdout);
	n = readint(),m = readint();
	for(int i = 1;i <= n;++i){
		orirank[i] = readint();
	}
	for(int i = 1;i <= n;++i){
		play(i);
		clear();
	}
	for(int i = 1;i <= m;++i){
		cout << ans[i] << ' '; 
	}
	return 0;
}

//CCF我希望下午你能对我好一点，我求你让过S组吧，我没什么好给你的，我只能给你卖个艺了
/*
先帝创业未半而中道崩殂，今天下三分，益州疲敝，此诚危急存亡之秋也。
然侍卫之臣不懈于内，忠志之士忘身于外者，盖追先帝之殊遇，欲报之于陛下也。
诚宜开张圣听，以追先帝遗德，恢弘志士之气，不宜妄自菲薄，引喻失意，以塞忠谏之路也

侍中侍郎郭攸之、费祎、董允等，此皆良实，志虑忠纯，是以先帝简拔以遗陛下。
愚以为宫中之事，事无大小，悉以咨之，然后施行，必能裨补阙漏，有所广益

将军向宠，性行淑均，试用与昔日，先帝称之曰能，是以众议举宠为都。
愚以为营中之事，事无大小，悉以咨之，必能使行阵和睦，优劣得所。

亲贤臣，远小人，此先汉之所以兴隆也。亲小人，远贤臣，此后汉之所以倾颓也。
先帝在时，每与臣论此事，未尝不叹息痛恨与桓、玲也。侍中尚书长史参军，此悉忠良死节之臣。
愿陛下亲之信之，则汉室之隆，可计日而待也。 
*/ 















