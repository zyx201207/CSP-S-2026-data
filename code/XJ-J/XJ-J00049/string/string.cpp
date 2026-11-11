#include<bits/stdc++.h>
using namespace std;
const int N=1e8+6;
long long n,maxn=-9999999,as,p;
char ak,ad; 
long long akioi[N],opp=0;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n; 
	for(long long i=1;i<=n;i++){
		cin>>as>>ak;
		akioi[(ak-'0')]+=as;
		if(ak!=ad){
			opp=2;
		}
		if(akioi[(ak-'0')]>maxn){
			maxn=akioi[(ak-'0')];
			p=1;
			ad=ak;
		} 
		if(akioi[(ak-'0')]==maxn&&ad!=ak){
			p++;
		}
	}
	if(p==1)
	{
		if(opp==0)
		{ 
			cout<<0;
		}
		else{
			
		} 
	}
	else{
		cout<<maxn;
	}
}

