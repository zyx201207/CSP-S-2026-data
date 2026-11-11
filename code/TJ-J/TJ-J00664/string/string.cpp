#include<iostream>
using namespace std;
long long n,num[200005],ans = 0,len = 1;
string ss = ""; 
char s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a;
	char x;
	long long ma = 0;
	for(int i = 1;i <= n;i++){
		cin>>a>>x;
		ma = max(ma,a);
		if(x == s[len - 1]){
			num[len - 1] += a;
		}
		else{
			num[len] = a;
			s[len] = x;
			len++;
		}
	}
	len--;
	if(n * ma >= 10000000){
		int i = 1,j = len;
		while(i < j){
			if((s[i] == s[j]) && (num[i] == num[j])) continue;
			if((s[i] == s[j]) && (num[i] != num[j])){
				if(num[i] > num[j]){
					int cnt = num[i] - num[j];
					ans += cnt;
					while(cnt){
						j--;
						if(cnt <= num[j]){
							num[j] -= cnt;
							cnt = 0;
						}
						else{
							cnt -= num[j];
							num[j] = 0;
						}
					}
					continue;
				}
				else{
					int cnt = num[j] - num[i];
					ans += cnt;
					while(cnt){
						i++;
						if(cnt <= num[i]){
							num[i] -= cnt;
							cnt = 0;
						}
						else{
							cnt -= num[i];
							num[i] = 0;
						}
					}
					continue;
				}
			}
			else{
				int cnt = num[i];
				ans += cnt;
				while(cnt){
					j--;
					if(cnt <= num[j]){
						num[j] -= cnt;
						cnt = 0;
					}
					else{
						cnt -= num[j];
						num[j] = 0;
					}
				}
				continue;
			}
			i++;
			j--;
		}
		cout<<ans<<endl;//写这么多只为了骗5分吗 
	}
	else{
		int kskbl = 0,ans1 = 0;
		for(int i = 1;i <= len;i++){
			for(int j = 1;j <= num[i];j++){
				ss += s[i];
				kskbl++;
			}
		}
		for(int i = 0,j = kskbl - 1;i < j;i++,j--){
			if(ss[i] != ss[j]) ans1++;
		}
		cout<<ans1<<endl;
	}
	return 0;
}

