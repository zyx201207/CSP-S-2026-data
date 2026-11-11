#include<bits/stdc++.h>
using namespace std;
const int N = 200010;
int arr[N],n;
long long ans;
char op[N];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i = 1;i<=n;i++)cin>>arr[i]>>op[i];
	int L = 1,R = n;
	while (L<R) {
		if (op[L]!=op[R]) ans+=min(arr[L],arr[R]);
		if (arr[L]==arr[R])L++,R--;
		else if (arr[L]>arr[R])arr[L]-=arr[R],R--;
		else arr[R]-=arr[L],L++;
	}
	cout<<ans;
}
