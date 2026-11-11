#include<bits/stdc++.h>
using namespace std;
int n,a[200002],t,i;
long long ans;
char c[200002];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)cin>>a[i]>>c[i];
	t=n;i=1;
	while(i<t){
		if(c[i]!=c[t]){
			if(a[i]>a[t]){
				a[i]-=a[t];
				ans+=a[t];
				t--;
			}
			else if(a[i]==a[t]){
				ans+=a[i];
				i++;
				t--;
			}
			else if(a[t]>a[i]){
				ans+=a[i];
				a[t]-=a[i];
				i++;
			}
		}
		else if(c[i]==c[t]){
			if(a[i]>a[t]){
				a[i]-=a[t];
				t--;
			}
			else if(a[i]==a[t]){
				i++;
				t--;
			}
			else if(a[t]>a[i]){
				a[t]-=a[i];
				i++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

