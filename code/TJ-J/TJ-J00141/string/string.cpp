#include <bits/stdc++.h>
using namespace std;
int n;long long a[200010],len1[200010],len2[200010],ans,len3[200010],len4[200010],len;string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i] >> s[i];
		len+=a[i];
	}
	if(len%2==1){
		int l1=len/2;
		int j=1;
		for(int i=l1-1;i>=0;i--){
			len1[j]=s[i];
			j++;
		}
		j=1;
		for(int i=l1+1;i<=len-1;i++){
			len2[j]=s[i];
			j++;
		}
		for(int i=1;i<=l1;i++){
			if(len1[i]!=len2[i]){
				ans++;
			}
		}
	}
	else{
		int l2=len/2;
		int x=1;
		for(int i=l2-1;i>=0;i--){
			len3[x]=s[i];
			x++;
		}
		x=1;
		for(int i=l2;i<=len-1;i++){
			len4[x]=s[i];
			x++;
		} 
		for(int i=1;i<=l2;i++){
			if(len3[i]!=len4[i]){
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}

