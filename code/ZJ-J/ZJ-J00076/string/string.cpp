#include<bits/stdc++.h>
using namespace std;
int n;
pair<char,long long>a[200001];
long long b[26],ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].second>>a[i].first;ans+=a[i].second;
	}
	if(n<=1){
		cout<<0;return 0;
	}
	else
	if(n==2){
		if(a[1].first==a[2].first){
			cout<<0;return 0;
		}
		else{
			cout<<min(a[1].second,a[2].second);return 0;
		}
	}
	else{
	    int num=26;
		for(int i=1;i<=26;i++)
			for(int j=1;j<=n;j++)
				if(a[j].first=='a'+i-1)
					b[i]+=a[j].second;
	    long long ma=0;
	    sort(b+1,b+num+1);
		cout<<ans-b[25];
	}
}
