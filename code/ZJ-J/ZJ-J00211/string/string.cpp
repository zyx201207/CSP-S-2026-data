#include<bits/stdc++.h>
using namespace std;
#define ip long long 
struct tyr{
	ip lr;char d;
}a[100005],b[100005];
ip opw[100005];
ip  ans=0,at=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ip n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].lr>>a[i].d;
	}
	b[1].lr=a[1].lr;b[1].d=a[1].d;
	int tyt=1;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=2;i<=n;i++){
		if(a[i].d==b[tyt].d)b[tyt].lr+=a[i].lr;
		else{
			tyt++;
			b[tyt].d=a[i].d;
			b[tyt].lr=a[i].lr;
		}
	}
	
	if(tyt==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=tyt;i++)opw[i]=opw[i-1]+b[i].lr;
	if(opw[tyt]%2==0){
		int mid=opw[tyt]/2;
		for(int i=1;i<=tyt;i++){
			if(mid>opw[i-1]&&mid<=opw[i]){
				at=i;
				break;
			}
		}
		if(mid!=opw[at]){
			for(int i=tyt;i>=at+1;i--){
				b[i+1].d=b[i].d;
				b[i+1].lr=b[i].lr;
			}
			b[i+1].d=b[i].d;b[i+1].lr=pow[i+1]-mid;b[i].lr=b[i].lr-b[i+1].lr;
		}
		//for(int i=1;i<=tyt;i++)cout<<b[i].lr<<' '<<b[i].d<<'\n';
		
	}
	return 0;
}
