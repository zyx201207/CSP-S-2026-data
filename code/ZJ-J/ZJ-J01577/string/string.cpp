#include<bits/stdc++.h>
using namespace std;
int n;
char s[200005];
int a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	long long sum = 0;
	for(int i = 1;i<=n;i++){
		scanf("%d %c",&a[i],&s[i]);
		sum+=a[i];
	}
	int cur1 = 1,cur2 = n,yu1 = 0,yu2 = 0;
	long long ans = 0,cnt1 = a[1],cnt2 = a[n];
	while(cur2 - cur1 > 0){
		while(yu1 > 0){
			if(a[cur2] <= yu1){
				yu1-=a[cur2];
				if(s[cur1] != s[cur2])ans+=a[cur2];
				cur2--;
				cnt2+=a[cur2];
			}
			else{
				yu2 = a[cur2] - yu1;
				if(cnt2 >= sum/2)yu2 -= cnt2-sum/2;
				if(s[cur1]!=s[cur2])ans+=yu1;
				yu1 = 0;
				cur1++;
				cnt1+=a[cur1];
			}
		}
		while(yu2 > 0){
			if(cur2 - cur1 <= n%2)break;
			if(a[cur1] <= yu2){
				yu2-=a[cur1];
				if(s[cur1] != s[cur2])ans+=a[cur1];
				cur1++;
				cnt1+=a[cur1];
			}
			else{
				yu1 = a[cur1] - yu2;
				if(cnt1 >= sum/2)yu1 -= cnt1-sum/2;
				if(s[cur2]!=s[cur1])ans+=yu2;
				yu2 = 0;
				cur2--;
				cnt2+=a[cur2];
			}
		}
		if(yu1 == 0 && yu2 == 0){
			if(a[cur1] > a[cur2]){
				yu1 = a[cur1] - a[cur2];
				if(cnt1 >= sum/2)yu1 -= cnt1-sum/2;
				if(s[cur1] != s[cur2])ans+=a[cur2];
				cur2--;
				cnt2+=a[cur2];
			}
			if(a[cur1] < a[cur2]){
				yu2 = a[cur2] - a[cur1];
				if(cnt2 >= sum/2)yu2 -= cnt2-sum/2;
				if(s[cur1] != s[cur2])ans+=a[cur1];
				cur1++;
				cnt1+=a[cur1];
			}
			else{
				if(s[cur1] != s[cur2])ans+=a[cur1];
				cur1++,cur2--;
				cnt1+=a[cur1],cnt2+=a[cur2];
			}
		}
	}
	cout << ans;
	return 0;
}