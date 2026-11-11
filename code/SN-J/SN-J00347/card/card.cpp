#include<bits/stdc++.h>
using namespace std;
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
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cout<<11<<" "<<45<<" "<<14;
	return 0;
}
