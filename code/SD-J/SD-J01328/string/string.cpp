#include<bits/stdc++.h>
using namespace std;
char zifu[200010];
long long geshu[200010];
long long ans=0;
long long n;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
	cin>>n;
	for(long long i=1; i<=n; i++)cin>>geshu[i]>>zifu[i];
	long long zuo=1,youu=n;
	while(zuo<youu) {
		if((zuo+1==youu)&&zifu[zuo]!=zifu[youu]) {
			ans+=min(geshu[zuo],geshu[youu]);
			break;
		}
		if(zifu[zuo]==zifu[youu]) {
			if(geshu[zuo]==geshu[youu]) {
				geshu[zuo]=0;
				geshu[youu]=0;
				zuo++;
				youu--;
			} else if(geshu[zuo]>geshu[youu]) {
				geshu[zuo]-=geshu[youu];
				geshu[youu]=0;
				youu--;
			} else if(geshu[zuo]<geshu[youu]) {
				geshu[youu]-=geshu[zuo];
				geshu[zuo]=0;
				zuo++;
			}
		} else if(zifu[zuo]!=zifu[youu]) {
			if(geshu[zuo]==geshu[youu]) {
				ans+=geshu[zuo];
				geshu[youu]=0;
				geshu[zuo]=0;
				zuo++;
				youu--;
			} else if(geshu[zuo]<geshu[youu]) {
				geshu[youu]-=geshu[zuo];
				ans+=geshu[zuo];
				geshu[zuo]=0;
				zuo++;
			} else if(geshu[zuo]>geshu[youu]) {
				geshu[zuo]-=geshu[youu];
				ans+=geshu[youu];
				geshu[youu]=0;
				youu--;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
