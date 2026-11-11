#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<string>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bitset>

using namespace std;
using ll=long long;
using ull=unsigned long long;
using lb=long double;
using pii=pair<int,int>;
using pll=pair<long long,long long>;
using pil=pair<int,long long>;
using pli=pair<long long,int>;

const int N=4e5+9;
int n;
ll sum;
char c[N];
int a[N],S[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	string s="";
	for(int i=1; i<=n; i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		if(a[i] >= 1e9)continue;
		for(int j=1; j<=a[i]; j++){
			s+=c[i];
		}
	}
	
	if(sum >= 1e9){
		cout<<sum/2<<'\n';
		return 0;
	}
	
	int ans=0;
	int len=s.length();
	for(int i=0; i<len/2; i++){
		if(s[i] != s[len-i-1])ans++;
	}
	cout<<ans<<'\n';

	return 0;
}