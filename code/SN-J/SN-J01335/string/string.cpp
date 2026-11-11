#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5+6;

int n;
string s;
struct duan{
	int m;
	char c;
}a[maxn];
ll sum;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin>>a[i].m>>a[i].c;
		sum+=a[i].m;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].m;j++)
			s+=a[i].c;
	}
	if((sum/2)*2==sum){
		int i1=0,j1=sum/2-1;
		int i2=sum/2,j2=sum-1;
		bool flag1 = 1,flag2 = 1;
		while(i1<=i2){
			if(s[i1]!=s[j2]){
				flag1=0;break;
			}
			i1++,j2--;
		}
		while(j1<=j2){
			if(s[j1]!=s[i2]){
				flag2=0;break;
			}
			j1++,i2--;
		}
		if(!(flag1&&flag2)) cout<<abs(j1-i1+1);
		else cout<<0;
	}
	else{
		int i1=0,j1=sum/2-1;
		int i2=sum/2+1,j2=sum-1;
		bool flag1 = 1,flag2 = 1;
		while(i1<=j1){
			if(s[i1]!=s[j1]){
				flag1=0;break;
			}
			i1++,j1--;
		}
		while(i2<=j2){
			if(s[i2]!=s[j2]){
				flag2=0;break;
			}
			i2++,j2--;
		}
		if(!(flag1&&flag2)) cout<<abs(j1-i1+1);
		else cout<<0;
	}
	return 0;
}

