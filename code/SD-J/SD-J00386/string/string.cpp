#include<bits/stdc++.h>
using namespace std;
struct d{
	long long g;
	char h;
} a[20010],b[20010];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].g>>a[i].h;
	}
	for(int i=1;i<=n;i++){
		b[i].g=a[n-i+1].g;
		b[i].h=a[n-i+1].h;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i].g==0 or b[i].g==0){
			continue; 
		}
		if(a[i].g>b[i].g){
			int m=a[i].g-b[i].g;
			int j=i+1;
			while(m){
				if(m<=b[j].g){
					if(b[j].h!=a[j].h){
						ans+=m;
					}
					b[j].g-m;
					m=0;
				}
				else{
					if(b[j].h!=a[j].h){
						ans+=a[j].g;
					}
					b[j].g=0;
					m-=b[j].g;
				}
				j++;
			} 
		}
		else if(a[i].g<b[i].g){
			int m=b[i].g-a[i].g;
			int j=i+1;
			while(m){
				if(m<=a[j].g){
					if(a[j].h!=b[j].h){
						ans+=m;
					}
					a[j].g-m;
					m=0;
				}
				else{
					if(a[j].h!=b[j].h){
						ans+=a[j].g;
					}
					a[j].g=0;
					m-=a[j].g;
				}
				j++;
			} 
		}
		else if(a[i].h!=b[i].h){
			ans+=a[i].g;
		}
	}
	cout<<ans/2;
	return 0;
}
