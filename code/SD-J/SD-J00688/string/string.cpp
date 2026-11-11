#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
const int M=2*1e5+5;
int num[N],n,x;
char ch[M];
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>ch[i];
		x+=num[i];
	}
	ll y=x/2;
	ll pos=0,pon=0;
	for(int i=n;i>=1;i++){
		if(pos<y){
			pos+=num[i];
			pon++;
			if(pos>y){
				pos=y;
				break;
			}
		}
	}
	int j=1;
	for(int i=n;i>=pon;){
		if(ch[i]==ch[j]){
			pos-=num[i];
		}
		if(num[i]==num[j]||num[i]>=num[j]){
		    j++;
				
		}
		else{
			num[i]-=num[j];
			i--;
		}
		if(num[j]==num[i]){
			num[j]=0;
			num[i]=0;
			i--;
		}
	}
	cout<<pos;
	return 0;
}

