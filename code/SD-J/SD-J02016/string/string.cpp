#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
deque<char> q;
int g;
char x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>g>>x;
		for (int j=1;j<=g;j++){
			q.push_back(x);
		}
	}
	if (!q.empty()){
		int l=1,r=q.size(),sum=0;
		if (n%2==0){
			while (l<r&&!q.empty()){
				if (q.front()==q.back()){
					l++,r--;
				}
				else{
					sum++;
					l++,r--;
				}
			}
			cout<<sum;
		}
		else{
			while (l<r&&!q.empty()){
				if (q.front()==q.back()){
					l++,r--;
				}
				else{
					sum++;
					l++,r--;
				}
			}
			cout<<sum;
		}
	}
	
	return 0;
}
