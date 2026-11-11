#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long l;
pair <long long,char> d[20005];
string s="";
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>d[i].first>>d[i].second;
		l=l+d[i].first;
	}
	int i=0,j=n-1;
	for(;i<j;) {
		if(d[i].second!=d[j].second) {
			ans+=min(d[i].first,d[j].first);
		}
		if(d[i].first>d[j].first) {
			d[i].first-=d[j].first;
			j--;
		}
		else if(d[i].first<d[j].first) {
			d[j].first-=d[i].first;
			i++;
		}
		else if(d[i].first==d[j].first) {
			j--,i++;
		}
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
