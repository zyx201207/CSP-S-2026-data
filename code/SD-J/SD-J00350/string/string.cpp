#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll max5,ans,n,totlen,ltlt=1,ltrt,rtlt,rtrt,lt2,rt2,div2,div3,div4,div5;
struct str{
	ll lenn;
	char ch;
}a[200003];
void yubei(){
	totlen*=n;
	rtrt=totlen;
	ltrt=totlen>>1;
	rtlt=totlen&1?ltrt+2:ltrt+1;
	//div=totlen&1?ltrt+1:ltrt;
	for(int i=1;i<=n;i++){
		lt2=rt2+1;
		rt2=lt2+a[i].lenn-1;
		if(lt2<=ltrt&&ltrt<=rt2){
			div2=i;div3=ltrt-lt2+1;
		}if(lt2<=rtlt&&rtlt<=rt2){
			div4=i;div5=ltrt-lt2+1;
		}
	}
}ll solve(){
	if(n==1)return 0;
	if(max5==1){
		int i=totlen>>1;
		int j=totlen&1?i+2:1+i;
		for(;i>=1,j<=totlen;i--,j++){
			if(a[i].ch!=a[j].ch)ans++;
		}return ans;
	}
	for(;ltrt>=1&&rtlt<=n;){
		int rt3=a[div4].lenn-div5+1;
		int lt3=div3;
		if(lt3>rt3){
			ans+=(a[div2].ch==a[div4].ch)?0:rt3;
			div4++;div5=1;
			div3-=rt3;
		}else if(lt3<rt3){
			ans+=(a[div2].ch==a[div4].ch)?0:lt3;
			div2--;div3=a[div2].lenn;
			div5+=lt3;
		}else{
			ans+=(a[div2].ch==a[div4].ch)?0:lt3;
			div3=1;
			div5=a[div4].lenn;
		}
	}
}int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].lenn>>a[i].ch;
		totlen+=a[i].lenn;max5=max(max5,a[i].lenn);
	}yubei();
	cout<<solve();
	return 0;
}/*
e1 7-8
e2 2-4
e3 13-16
e4 10-12
e5 13-16
e6 19-21
E7 1
E8 5-6
E9 9
E10 17-18
E11 22-25
//24pts
*/
