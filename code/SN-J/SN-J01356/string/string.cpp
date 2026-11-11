#include<bits/stdc++.h>
using namespace std;
long long p[200010];
char s[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int R,w;
	unsigned long long ans=0;
	cin >> R;
	for(int iw=1;iw<=R;iw++){
		cin >> p[iw];
		cin >> s[iw];
		if(s[iw]==s[iw-1]){
			p[iw-1] += p[iw];
			p[iw] = 0;
			iw--;
			R--;
		}
	}
	
	
	
	int r=R/2+1;
	int j=R;
	for(int i=1;i<=j;i++){

			if(j<i) break;
			if(s[i]==s[j]){
				if(p[i]<p[j]){
					p[j] -= p[i];
					j++;
				}else if(p[j]<p[i]){
					p[i] -= p[j];
					i--;
				}else{
				}
			}else{
				if(p[i]<=p[j]){
					p[j] -= p[i];
					ans += p[i];
					j++;
				}else if(p[j]<=p[i]){
					p[i] -= p[j];
					ans += p[j];
					i--;
				}else{
					ans += p[j];
				}
			}
			j--;
			
		
	}
	cout << ans;
	return 0;
}

