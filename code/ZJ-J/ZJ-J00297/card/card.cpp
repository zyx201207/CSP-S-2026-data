#include<bits/stdc++.h>
#include<queue>
using namespace std;

int main(){
	freopen( "card.in" , "r" , stdin );
	freopen( "card.out" , "w" , stdout );
	long long n , m , top = 1;
	cin >> n >> m;

	vector<long long> ans( 300010 , 0 );
	queue<long long> pd;
	for( long long i = 1 ; i <= n ; i++ ){
		long long t;
		cin >> t;
		pd.push(t);
	}
	long long j = 1;
	while( !pd.empty() ){
		vector<long long> a( 300010 , -1 );
		vector<long long> w( 300010 , -1 );
		long long top = 0;
		for( long long i = 1 ; i < j ; i++ ){
			pd.pop();
		}
		long long t = pd.size();
		for( long long i = 1 ; i <= t; i++ ){
			if( a[pd.front()] = -1 ){
				top++;
				a[pd.front()] = top;
				w[top] = pd.front();
				pd.pop();
			}else{
				top = a[pd.front()];
				for( long long k = top ; k <= w.size() ; k++ ){
					pd.push(w[k]);
					a[w[k]] = -1;
					w[k] = -1;
				}
				top++;
				w[top] = pd.front();
			}
			pd.pop();
		}
		if( top != 0 ){
			for( long long i = 1 ; i <= top ; i++ ){
				ans[w[i]]++;
				pd.push(w[i]);
				cout << ans[w[i]] << endl;
			}
		}
	}
	for( long long i = 1 ; i <= m ; i++ ){
		if( ans[i] != 0 ){
			cout << ans[i] << ' ';
		}
	}
	fclose( stdin );
	fclose( stdout );
	return 0;
}
