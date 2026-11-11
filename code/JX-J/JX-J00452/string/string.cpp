#include<bits/stdc++.h>
using namespace std;
int n;
int a;char b;
int sw=0,cnt2,qwp,rp=0;long long cnt=0,ans=0;
char s[100000000],c[100000000],c2[100000000],h[1000000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
		cin>>a>>b;
		cnt+=a;
		for(int i=0;i<a;i++){
			s[sw]=b;sw++;
			if(i==0){
				qwp=s[sw];rp++;
			}else{
				if(s[sw]==qwp)rp++;
			}
		}
	}
	if(rp==cnt){cout<<"0";return 0;}
	cnt2=cnt/2;
	for(int i=0;i<cnt2;i++){
		c[i]=s[i];
	}
	int q=0;
	
	for(int i=cnt2-1;i>0;i--){
		c[i]=c2[q];q++;
	}
	
	int w=0;
		for(int i=cnt2;i<cnt;i++){
			h[w]=s[i];w++;
		}
		for(int i=0;i<cnt2;i++){
			if(c2[i]!=h[i]){ans++;}
		}
	cout<<ans;
    return 0;
}
