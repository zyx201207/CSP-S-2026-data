#include <bits/stdc++.h>
using namespace std;

int n;
int a[200005];
char s[200005];
long long ans=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		cin >> s[i];
	}

	int l=1,r=n;
	while(l<r){
		if(a[l]<a[r]){
			if(s[l]!=s[r]){
				ans+=a[l];
			}
			a[r]-=a[l];
			l++;
		}
		else if(a[l]>a[r]){
			if(s[l]!=s[r]){
				ans+=a[r];
			}
			a[l]-=a[r];
			r--;
		}
		else{
			if(s[l]!=s[r]){
				ans+=a[r];
			}
			l++;
			r--;
		}
	}
	
	//for(int i=1;i<=n;i++)cout << a[i] <<' '<<s[i]<<endl;
	cout << ans;
	return 0;
}