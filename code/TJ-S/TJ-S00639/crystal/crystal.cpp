#include<bits/stdc++.h>
using namespace std;
long long a,b,c[1000000],d[1000000],e,r,t,p[1000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>b;
	t=b;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	if(a<=5000){
		sort(c,c+a);
		for(int i=0;i<a;i++){
			d[i]=c[i]-c[0];
		}
		for(int i=0;i<a;i++){
			b=t;
			r=0;
			for(int j=0;j<i;j++){
				p[j]=d[i]-d[j];
			}
			sort(p,p+i);
			for(int j=0;j<i;j++){
				if(p[j]<=b){
					r++;
					b-=p[j];
				}
				else break;
			}
			if(r+1>e) e=r+1;
		}
		cout<<e;
		return 0;
	}
	else{
		sort(c,c+a);
		r=c[1]-c[0];
		t=1;
		for(int i=0;i<a;i++){
			if(t*r<=b){
				b-=r*t;
				e++;
				t++;
			}
			else break;
		}
		cout<<e;
	}
	return 0;
}
