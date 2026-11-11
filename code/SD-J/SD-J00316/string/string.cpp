#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct str{
	long long m;
	char c;
}a[200005];  
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].c;
	}
	for(int i=1,j=n;i<j;){
		if(a[i].c==a[j].c){
			if(a[i].m>a[j].m){
				a[i].m-=a[j].m;
				j--;
			}
			else if(a[i].m<a[j].m){
				a[j].m-=a[i].m;
				i++;
			}
			else{
				a[j].m=0;
				a[i].m=0;
				i++,j--;
			}
		}
		else{
			if(a[i].m>a[j].m){
				a[i].m-=a[j].m;
				ans+=a[j].m;
				j--;
			}
			else if(a[i].m<a[j].m){
				a[j].m-=a[i].m;
				ans+=a[i].m;
				i++;
			}
			else{
				
				ans+=a[i].m;
				a[j].m=0;
				a[i].m=0;
				i++,j--;
			}	
		}
		
	}
	cout<<ans;
	return 0;
}

