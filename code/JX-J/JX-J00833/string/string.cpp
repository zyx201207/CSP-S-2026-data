#include<bits/stdc++.h>
using namespace std;

struct node{
	long long int a;
	char b;
};
node k[1000];
node m[1000];
int n,o=1;
long long int sum=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k[i].a>>k[i].b;
	}
	for(int i=n-1,j=0;i>=0;i--,j++){
		m[j].a=k[i].a;
		m[j].b=k[i].b;
	}
	for(int i=0,j=n-1;i<j;i++,j-=o){
		if(m[i].b!=m[j].b){
			for(int w=j;w>i;w--){
				if(m[w].b!=m[i].b){
					if(m[w].a>=m[i].a){
						sum+=m[i].a;
						m[w].a-=m[i].a;
						m[i].a=0;
						o=0;
						break;
					}
					else{
						sum+=m[w].a;
						m[i].a-=m[w].a;
						m[w].a=0;
						o=1;
					}
				}
			}
		}
		else if(m[i].a!=m[j].a&&i+1!=j){
			if(m[i].a>m[j].a){
				sum+=m[i].a-m[j].a;
				m[i].a-=m[j].a;
				m[j].a=0;
				o=1;
			}
			else{
				sum+=m[j].a-m[i].a;
				m[j].a-=m[i].a;
				m[i].a=0;
				o=1;
			}
		}
	}
	cout<<sum;
	
	return 0;
}
