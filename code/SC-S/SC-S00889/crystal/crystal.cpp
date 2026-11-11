#include<bits/stdc++.h>
using namespace std;
//          CCCCCCC      CCCCCCC    FFFFFFF
//        CC           CC           F
//       CC           CC            FFFFFFF
//        CC           CC           F
//         CCCCCC       CCCCCC      F
//[14:41] started
//[14:55] finished #1#2check
//[15:12] that soooo guiyi.shen shi gui yi.
//[15;17] that soooo gui yi!the same program output the different answer.
//[15:23] oh,my mistake,the long long use "%d" not "%lld"
//[15:30] oh,no,the "crystal.exe" is be a zombie!my code is 100% correct.
//[15:33] the error is output too much.let me fix it.
//[15:35] the another error is remain ops.let me fix it again.
//[15:46] denied again?I'm not add the output.
//[15:48] SIGSEGV,classic.I'll fix this.
//[15:52] the problem iz in the sort();
//[15:53] oh,my mistake,the long long use "%d" not "%lld" again. :(
//[15:58] finished #3check
typedef long long ll;
ll a[500005];
bool great(ll a,ll b){
	return a>b;
}
int main(){
	//5 5
	//1 2 4 8 9
	//average:4.8
	//near:4
	//1+3 2+2 4 8 9->3
	
	//5 8
	//-3 -1 2 2 7
	//average:1.6
	//near:2
	//-3+5 -1+3 2 2 7->4
	ll expect=315275;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll n,m;
	scanf("%lld%lld",&n,&m);
	ll ave=0;
	for(ll i=0;i<n;i++){
		ll x=0;
		scanf("%lld",&x);
		a[i]=x;
		ave+=x;
	}
	ave=ave/n;//pin jun
	sort(a,a+n);//nlogn = 500000 * 19 = 9 500 000(9.5 mil)
	
	ll pos=-1;
	ll near=2147483647;
	for(ll i=0;i<n;i++){
		ll s=abs(a[i]-ave);
		if(near>=s){
			pos=i;
			near=s;
		}
	}
	if(pos==-1)return 1;
	ll merge=0;
	sort(a,a+pos,great);//you xian bao zheng xu yao xiao de(tan xin)
	int pos1=pos;
	//5 3 4 1 2
	//ave:3 ops:6
	//sor1:1 2 3 4 5
	//sor2:2 1 3 4 5
	//        pos
	//befo:3 3 3 4 5 ops:3
	//agai:4 4 4 4 5 ops:0
	//out:4
	for(ll i=0;i<=pos;i++){
		ll needops=ave-a[i];//xu yao cao zuo dian shu
		if(m>=needops){//cao zuo zui xiao de
			m-=needops;//spend
			merge++;//he bing cheng gong
		}else{
			break;//dou bu gou le zhi jie diao
		}
	}
	int am=0;
	int p=0;
	if(m>0){
		pos++;
		while(pos<n){
			ll npos=a[pos];
			ll needops=(pos-1)*(npos-a[pos-1]);//gei qian mian quan bu jia dao xia yi ge
			int extraops=ave-a[p];
			if(extraops>needops){
				m+=extraops;
				m-=needops;
				a[p]=0x7f7f7f7f;
				if(p<pos1-1){
					p++;
				}
				pos++;
			}else if(m>=needops){
				m-=needops;
				am++;merge++;
				pos++;
			}else{

				break;
			}
		}
	}
	
	
	printf("%lld",merge);
	return 0;
}