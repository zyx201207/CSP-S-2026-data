#include <bits/stdc++.h>
using namespace std;
long long int n,s;
struct st
{
	long long a;char c;	
}a[200010];
//vector<st> a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].a>>a[i].c;
	}
	int i=0,j=n-1;
	while(i<=j){
		if(a[i].c!=a[j].c){
			if(a[i].a>a[j].a){
				s+=a[j].a;a[i].a-=a[j].a;j--;
			}else if(a[i].a<a[j].a){
				s+=a[i].a;a[j].a-=a[i].a;i++;
			}else{
				s+=a[i].a;i++;j--;
			}
		}else{
			if(a[i].a>a[j].a){
				a[i].a-=a[j].a;j--;
			}else if(a[i].a<a[j].a){
				a[j].a-=a[i].a;i++;
			}else{
				i++;j--;
			}
		}
	}
	cout<<s;
	return 0;
}
