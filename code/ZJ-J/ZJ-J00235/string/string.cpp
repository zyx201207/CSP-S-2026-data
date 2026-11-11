#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<stack>
#include<cmath>
using namespace std;
struct node{
	int sl;
	char zm;
}a[200010];
long long n,i,l,r,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i].sl>>a[i].zm;
	}
	r=1;
	l=n;
	while(r<=l){
		if(r==l){
			cout<<s;
			return 0;
		}
		if(a[r].zm==a[l].zm){
			if(a[r].sl<a[l].sl){			
				a[l].sl-=a[r].sl;
				r++;
			}else{
				a[r].sl-=a[l].sl;
				l--;
			}			
		}else{
			if(a[r].sl<a[l].sl){		
				s+=a[r].sl;	
				a[l].sl-=a[r].sl;
				r++;
			}else{
				s+=a[l].sl;
				a[r].sl-=a[l].sl;
				l--;
			}				
		}
	}
	return 0;
}
