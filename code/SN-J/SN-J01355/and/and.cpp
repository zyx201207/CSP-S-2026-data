#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 200000 + 7;
int a[N];
int pre[N],suf[N];
void debug(int x){
	stack<int> st;
	st.pop();
	while(x){
		st.push(x%2);
		x/=2;
	}
	int cnt = 0;
	for(int i = 1;i<=6-st.size();i++) cout << "0";
	while(!st.empty()){
		cout << st.top();
		st.pop();
	}
}
void toA(){
	sort(a+1,a+n+1);
	int ans = a[n];
	for(int i = 1;i<=m;i++){
		ans = ans & (a[n-i+1]);
		
	}
	cout << ans;
}

void toB(){
	cout << (1 << n) - (1 << (n-m+1));
}

void toE(){
	pre[1] = a[1];
	for(int i = 2;i<=n;i++){
		pre[i] = pre[i-1] & a[i];
	}
	
	suf[n] = a[n];
	for(int i = n-1;i>=1;i--){
		suf[i] = suf[i+1] & a[i];
	}
	int ans = -1;
	pre[0] = (1 << 31)-1;
	suf[n] = (1 << 31)-1;
	for(int i = 1;i<=n;i++){
		ans = max(ans,pre[i-1] & suf[i+1]);
	}
	cout << ans;
}
bool fullOne(int x){
	bool result = true;
	while(result && x){
		result = (x%2);
		x/=2;
	}
	return result;
}
int michele[4];
int dfsans = -1;
void dfs(vector<int> vec,int idx,int len){
	if(len == m){
		int round = 0;
		for(int i = 0;i<vec.size();i++){
			if(round==0) round = vec[i];
			else{
				round &= vec[i];
			}
		}
		dfsans = max(dfsans,round);
		return;
	}
	for(int i = idx + 1;i<=n;i++){
		vec.push_back(a[i]);
		dfs(vec,idx+1,len+1);
		vec.pop_back();
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	bool isA = true;
	bool isB = fullOne(n-1);
	bool isC = (n == m);
	bool isD = (m==1);
	bool isE = (m == n-1);
	bool isF = true;
	if(isC){
		int ans = -1;
		for(int i = 1;i<=n;i++){
			cin >> a[i];
			if(ans == -1) ans = a[i];
			else{
				ans &= a[i];
			}
		}
		cout << ans;
		return 0;
	}
	for(int i = 1;i<=n;i++){
		cin >> a[i];
		if(isA) isA = fullOne(a[i]);
		if(isB) isB = (a[i] == i-1);
		if(isF) isF = (a[i] < 4);
		if(isF) michele[a[i]]++;
	}
	if(isA){
		toA();
		return 0;
	}
	if(isB){
		toB();
		return 0;
	}
	if(isE){
		toE();
		return 0;
	}
	if(isF){
		int ans = 0; 
		if(michele[3] >= m) ans = max(ans,3);
		if(michele[3] + michele[2] >= m) ans = max(ans, 2);
		if(michele[1] >= m) ans = max(ans, 1);
		cout << ans;
		return 0;
	}
	if(isD){
		int ans = -1;
		for(int i = 1;i<n;i++){
			for(int j = i+1;j<=n;j++){
				ans = max(ans,a[i]&a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	if(m==2){
		int ans = -1;
		for(int i = 1;i<n-1;i++){
			for(int j = i+1;j<n;j++){
				for(int k = j+1;k<=n;k++){
					ans = max(ans,a[i]&a[j]&a[k]);
				}
			}
		}
		cout << ans;
		return 0;
	}
	if(n <= 20){
		vector<int> vec;
		vec.clear();
		dfs(vec,0,0);
		cout << dfsans;
	}else{ //²£Á§´óÅÚ
		int ans = 0;
		sort(a+1,a+n+1);
		int cnt = 0;
		for(int i = n;cnt <= m;i--){
			if(i == n) ans = a[i];
			else ans &= a[i];
			cnt++;
		}
		cout<<ans;
	}
	//michele!!!
//	int ans = -1;
//	do{
//		int round = a[1];
//		for(int i = 2;i<=m;i++) round &= a[i];
//		ans = max(ans,round);
//	}while(next_permutation(a+1,a+n+1)); 
	
//	cout << ans;
	return 0;
} 
