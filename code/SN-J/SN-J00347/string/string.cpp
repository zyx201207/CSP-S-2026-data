#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],ans,cnt,q;
string s;
char x;
int read() {
	int f=1,ans=0;
	char ch=getchar();
	if(!isdigit(ch)) {
		if(ch=='-') {
			f=-1;
		}
		ch=getchar();
	}
	while(isdigit(ch)) {
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return f*ans;
}
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=0; i<n; i++) {
		a[i]=read();
		cnt+=a[i];
		cin>>x;
		s+=x;
	}
	for(int i=0,j=s.size()-1; i<j;) {	
		if(s[i]!=s[j]) {
			if(a[i]==a[j]) {
				ans+=a[i];
				i++,j--;
				continue;
			}
			ans+=min(a[i],a[j]);
			if(a[i]<a[j]) {
				
				q=a[j]-a[i];
				i++;
				while(q-a[i]>=0) {
					q-=a[i];
					ans+=a[i];
					i++;
				}
				a[i]-=q;
				ans+=q;
				q=0;
				j--;
				continue;
			}
			if(a[i]>a[j]) {
				q=a[i]-a[j];
				j--;
				while(q-a[j]>=0) {
					q-=a[j];
					ans+=a[j];
					j--;
				}
				a[j]-=q;
				ans+=q;
				q=0;
				i++;
				continue;
			}
		} else {
			if(a[i]==a[j]) {
				i++,j--;
				continue;
			}
			if(a[i]>a[j]) {
				q=a[i]-a[j];
				j--;
				while(q-a[j]>=0) {
					if(s[j]!=s[j+1]) {
						q-=a[j];
						ans+=a[j];
						j--;
					} else {
						q-=a[j];
						j--;
					}
				}
				if(s[j]!=s[j+1]) {
					a[j]-=q;
					ans+=q;
					i++;
				}
				continue;
			}
			if(a[i]<a[j]) {
				q=a[j]-a[i];
				i++;
				while(q-a[j]>=0) {
					if(s[j]!=s[j-1]) {
						q-=a[j];
						ans+=a[j];
						i++;
					} else {
						q-=a[j];
						i++;
					}
				}
				if(s[j]!=s[j-1]) {
					a[j]-=q;
					ans+=q;
					j--;
				}
				continue;
			}
		}
	}
	cout<<ans;
	return 0;
}
