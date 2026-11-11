//t 2026-10-31 8:52
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1e5+5;
long long n,a[2*N];
char s[2*N];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		if(s[i-1]==s[i]){
			a[i-1]+=a[i];
			i--;
			n--;
		}
	}
	//cout<<n;
	if(n==1){
		cout<<0;
		return 0;
	}else if(n==2){
		cout<<min(a[1],a[2]);
		return 0;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l]==a[r]&&s[l]!=s[r]){
			ans+=a[l];
			l++;
			r--;
			continue;
		}
		if(s[l]==s[r]){
			ans+=abs(a[l]-a[r]);
			if(abs(a[l]-a[r])==0){
				l++;
				r--;
				continue;
			}
			if(a[l]>a[r]){
				a[l]-=abs(a[l]-a[r]);
				a[r]=0;
				r--;
				continue;
			}else{
				a[l]=0;
				a[r]-=abs(a[l]-a[r]);
				l++;
				continue;
			}
		}else{
			ans+=min(a[l],a[r]);
			if(a[l]>a[r]){
				a[l]-=a[r];
				a[r]=0;
				r--;
				continue;
			}else{
				a[r]-=a[l];
				a[l]=0;
				l++;
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}
/*
aabbc
2 a
2 b
1 c
5%2==1
aabba
aaaaabbccdd

aacccbaaaa
6
100 a
100 a
100 a
100 b
100 b
100 b

aammmssssqppsssmmaazxa
9
2 a
3 m
4 s
1 q
2 p
3 s
2 m
1 a
1 a
1 z
1 z
1 a
avvzzzwww


 */
