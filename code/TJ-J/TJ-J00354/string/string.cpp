#include<bits/stdc++.h>
using namespace std;

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a[200005];
    char c[200005];
    long long sum=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	int h=1,t=n;
	for(int i=1;i<=n;i++){
		if(h==t) break;
		if(c[h]!=c[t]){
			sum=sum+min(a[h],a[t]);
			int x=max(a[h],a[t])-min(a[h],a[t]);
			if(a[h]>a[t]){
				a[h]=x;
				a[t]=0;
			}
			else{
				a[h]=0;
				a[t]=x;
			}
			if(a[h]==0&&a[t]!=0) h++;
			else if(a[t]==0&&a[h]!=0) t--;
			else{
				h++;
				t--;
			}
		}
		else{
			int x=max(a[h],a[t])-min(a[h],a[t]);
			if(a[h]>a[t]){
				a[h]=x;
				a[t]=0;
			}
			else{
				a[h]=0;
				a[t]=x;
			}
			if(a[h]==0&&a[t]!=0) h++;
			else if(a[t]==0&&a[h]!=0) t--;
			else{
				h++;
				t--;
			}
		}
	}
	cout<<sum;
	return 0;
}
