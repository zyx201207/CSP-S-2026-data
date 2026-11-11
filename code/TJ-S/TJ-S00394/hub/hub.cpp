#include<bits/stdc++.h>
using namespace std;
struct city(int x,int y){
	for (int i = t;i >= 1;i --){
		x -= s[i] - 1;
		y += s[i] + d[i-s[i]] + 1;
		if (x > y){
			break;
			return 0;
		}
	}
	return 1
};
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	int c,t;
	int lower = -1;
	int a[i],s[i],d[i];
	cin >> c >> t;
	cin >> n >> m;
	for (int i = 1;i <= t;i ++){
		cin >> a[i];
	}
	int count = 0;
	for (int i = 1;i <= n;i ++){
		for (int j = m;j >= m-s[i];j --){
			if (d[i] >= s[j]){
				count += min(d[i] + s[i] - a[i],d[j-a[i]] + s[j] + 1);
				while (count >= d[i] + s[j-1] + lower){
					lower += count;
					city();
				}
				if (count){
					break;
				}
			}
		}
	}
	for (int i = count+s[t];i >= min(count + s[n], s[h]+d[count];i--)){
		for (int j = 0;j <= max(count + d[h],a[i]);i ++){
			int flag = 0;
			flag += s[i];
			if (flag + d[i] > flag + s[count] && s[count] + max(count, a[s[count]] || flag >= a[h[i]-s[j]])){
				if (flag < min(s[h[j]],a[s[count]])){
					flag = s[j] - d[i];
				}
			}
		}
	}
	for (int i = 1;i <= t;i ++){
		cout << count << flag << endl;	
	}
	
	return 0;
}

