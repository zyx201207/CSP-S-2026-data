#include<iostream>
#include<stack>
using namespace std;
int t[300005],a[500005],anst[300005];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n;i++){
		for(int j = i;j<=n;j++){
			s.push(a[j]);
			t[a[j]]++;
			if(t[a[j]] >= 2){
				s.pop();
				t[a[j]]--;
				while(s.top() != a[j] && !s.empty()){
					t[s.top()]--;
					s.pop();
				}
			}
		}
		for(int j = 0;j<=m;j++){
			t[j] = 0;
		}
		while(!s.empty()){
			anst[s.top()]++;
			s.pop();
		}
	}
	for(int i = 1;i<=m;i++){
		cout << anst[i] << " ";
	}
    return 0;
}

