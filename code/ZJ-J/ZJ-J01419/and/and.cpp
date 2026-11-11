#include<bits/stdc++.h>

using namespace std;

int n,m;
int sum=-1e9,ans;
int f[31] = {2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};

struct student{
	int a;
	int b;
}o[200010];

bool cmp(student x,student y){
	if(x.b == y.b) return x.a > y.a;
	else return x.b < y.b;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> o[i].a;
	}
	if(m > 1){
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				if(o[i].a == o[j].a) sum = max(sum,o[i].a);
			}
		}
	}
	for(int i = 0;i < n;i++){
		for(int j = 30;j >= 0;j--){
			if(o[i].a > f[j]) continue;
			else o[i].b = f[j] - o[i].a;
		}
	}
	sort(o,o+n,cmp);
	ans = o[0].a;
	for(int i = 0;i < m;i++){
		ans &= o[i].a;
	}
	for(int i = 0;i < m-2;i++){
		if(i < 2 && o[i].a == sum) continue;
		sum &= o[i].a;
	}
	cout << max(ans,sum);
	return 0;
}
