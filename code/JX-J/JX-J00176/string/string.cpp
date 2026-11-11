#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int N=2e5+5;

ll a[N],ans;
char c[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;cin>>n;

	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}

	for(int i=1,j=n;i<j;){
		if(a[i]>a[j]){
			if(c[i]!=c[j])ans+=a[j];

			a[i]-=a[j];
			j--;
		}
		else if(a[i]==a[j]){
			if(c[i]!=c[j])ans+=a[i];

			j--,i++;
		}
		else if(a[i]<a[j]){
			if(c[i]!=c[j])ans+=a[i];

			a[j]-=a[i];
			i++;
		}
	}

	cout<<ans;

	return 0;
}