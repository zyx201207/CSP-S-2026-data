#include<bits/stdc++.h>
using namespace std;
long long n,m,o,l=1,ld,rd,ds;
char zm[27];
int zms[27];
long long a[1000000001];
char c[1000000001];
char s[1000000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >>a[i]>> c[i];
		for(int j=1;j<=a[i];j++){
			m+=1;
			s[m]=c[i];
		}
	}
	for(int i=1;i<=m;i++){
		if(zm[l]!=s[i]){
			for(int j=1;j<=l;j++){
				if(zm[j]==s[i]){
					zms[j]+=1;
					break;
				}
				l+=1;
				zm[l]=s[i];
				zms[l]+=1;
			}
		}else if(zm[l]==s[i]){
			zms[l]++;
		}
	}
	int l=1,r=m;
	while(r){
		if(s[l]!=s[r]){
			o+=1;
			break;
		}
		l+=1;
		r-=1;
	}
	l=1,r=m;
	if(o>=1){
		while(r){
			if(s[l]!=s[r]){
				for(int i=1;i<=l;i++){
					if(s[l]==zm[i]){
						ld=zms[i];
					}
					if(s[r]==zm[i]){
						rd=zms[i];
					}
				}
				if(ld>=rd){
					s[r]=s[l];
					ds+=1;
				}else{
					s[l]=s[r];
					ds+=1;
				}
			}
			l+=1;
			r-=1;
		}
	}

	cout<<ds;
	return 0;
}