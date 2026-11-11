#include<bits/stdc++.h>
using namespace std;
long long a,b[1000000],d,e,r=1,t=1,r2=1,t2;
char c[1000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b[i]>>c[i];
		d+=b[i];
	}
	t=d;
	d/=2;
	t2=a;
	while(1){
		if(c[t2]==c[r2]){
			if(b[r2]==b[t2]){
				r+=b[r2];
				t-=b[t2];
				r2++;
				t2--;
			}
			else if(b[r2]>b[t2]){
				r+=b[t2];
				t-=b[t2];
				b[r2]-=b[t2];
				t2--;
			}
			else if(b[r2]<b[t2]){
				r+=b[r2];
				t-=b[r2];
				b[t2]-=b[r2];
				r2++;
			}
		}
		else{
			if(b[r2]==b[t2]){
				e+=b[r2];
				r+=b[r2];
				t-=b[t2];
				r2++;
				t2--;
			}
			else if(b[r2]>b[t2]){
				e+=b[t2];
				r+=b[t2];
				t-=b[t2];
				b[r2]-=b[t2];
				t2--;
			}
			else if(b[r2]<b[t2]){
				e+=b[r2];
				r+=b[r2];
				t-=b[r2];
				b[t2]-=b[r2];
				r2++;
			}
		}
		if(r2>=t2){
			cout<<e;
			break;
		}
	}
	return 0;
}
