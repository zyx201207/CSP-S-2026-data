#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10,M = 3e5 + 10;

int a[N],res[M];

void out(stack<int> st){
	cout << "out:\n";
	while(!st.empty()){
		cout << st.top() << " \n"[st.size() == 1];
		st.pop();
	}
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m; scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	if(is_sorted(a + 1,a + 1 + n)){
		for(int i = 0;i <= m;i++) res[i] = n;
		for(int i = 1;i <= n;i++) if(a[i] != a[i - 1]) res[a[i - 1]] -= n - i + 1;
		for(int i = 1;i <= m;i++) printf("%d%c",res[i],i != m ? ' ' : '\n');
		return 0;
	}
	if(m == 2){
		res[a[n]] = n;
		for(int i = 1;i <= n;i++) res[3 - a[n]] += a[i] != a[n];
		printf("%d %d\n",res[1],res[2]);
		return 0;
	}
	for(int i = 1;i <= n;i++){
		//~ cout << "turn:" << i << "\n";
		stack<int> st;
		vector<bool> flag(m + 1,false);
		for(int j = i;j <= n;j++){
			if(flag[a[j]] == true) 
				while(st.top() != a[j]){
					flag[st.top()] = false;
					st.pop();
				}
			else{
				st.push(a[j]);
				flag[a[j]] = true;
			}
			//~ out(st);
		}
		//~ cout << "empty:" << st.empty() << "\n";
		//~ while(!st.empty()){
			//~ cout << st.top() << " \n"[st.size() == 1];
			//~ st.pop();
		//~ }
		//~ for(int i = 1;i <= m;i++) cout << flag[i] << " \n"[i == m];
		for(int i = 1;i <= m;i++) res[i] += flag[i];
	}
	for(int i = 1;i <= m;i++) printf("%d%c",res[i],i != m ? ' ' : '\n');
	return 0;
}
