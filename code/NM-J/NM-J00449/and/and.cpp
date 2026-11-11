#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,d=0;
	cin>>n>>m;
	long long a[20005],c[20005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>d){
			d=a[i];
		}
		int b=1,o=1;
		while(a[i]>=b){
			b=b*2;
			o=o*10;
		}
		b=b/2;
		o=o/10;
		int l=a[i];
		int p=0;
		while(p!=1){
			if(l>=b){
				l=l-b;
				c[i]+=1*o;
			}else{
				b=b/2;
				o=o/10;
			}
			if(l==1||l==0){
				p=1;
				c[i]+=l;
			}
		}
		
	}
	if(m==1){
		cout<<d;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
};
