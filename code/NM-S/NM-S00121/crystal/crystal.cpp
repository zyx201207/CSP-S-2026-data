#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long cy[1000005];

bool binary_chk(long long a){
	long long ch = 0;
	for(int i = 0;i < a;++i){
		ch += cy[a] - cy[i];
	}
	if(ch > m) return false;
	else return true;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 0;i < n;++i){
		cin >> cy[i];
	}
	sort(cy,cy+n,less<long long>());
	long long lb = 0,rb = n,mid;
	while(lb <= rb){
		mid = (lb+rb) / 2;
		if(binary_chk(mid)){
			lb = mid+1;
		}else{
			rb = mid-1;
		}
	}
	cout << lb;
	return 0; 
} 
