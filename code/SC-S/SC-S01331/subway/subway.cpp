#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5*1e5 + 5;
const int INF = 0x3f3f3f3f;
int c,n,m,d,q;
vector <int> w;
int k[505];
vector <vector<int> > a;
vector <vector<int> > sta;
vector <vector<int> > t;
vector <int> rx,ry;
vector <int> ans;



int search(int idrx,int idry){
	int idn = idrx;
	int sum = 0;
//	priority_queue <int,vector<int>,greater<int> > q;
	int mins = INF;
	int lnm;
//	printf("start search\n");
	for (int i = 0;i < sta[idrx].size();i++){
//		q.push(i);
		if (sta[idrx][i] < mins){
//			printf("init mins change\n");
			mins = sta[idrx][i];
			lnm = i;
		}
	}
	while (1){
//		int temp = q.top();
//		q.pop();
//		sum += temp;
		sum += mins;
//		printf("sum : %d\n",sum);
		mins = INF;
		int len = a[lnm].size();
		int temp = lnm;
		for (int i = 0;i < len;i++){
			if (a[lnm][i] == idry){
				sum += sta[idry][lnm];
				break;
			}
			for (int j = 0;j < k[a[lnm][i]];j++){
				if (t[lnm][i] + sta[a[lnm][i]][j] < mins){
					mins = t[lnm][i] + sta[a[lnm][i]][j];
					temp = j;
				}
			}
		}
		lnm = temp;
	}
	return sum;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	w.resize(m+5);sta.resize(m+5);
	a.resize(n+5);t.resize(n+5);
	rx.resize(q+5);ry.resize(q+5);ans.resize(q+5);
	
	for (int i = 0;i < m;i++){
		cin >> w[i];
		sta[i].resize(d+5);
	}
	for (int i = 0;i < n;i++){
		cin >> k[i];
		a[i].resize(k[i]+5);t[i].resize(k[i]+5);
		for (int j = 0;j < k[i];j++){
//			printf("cin line->station\n");
			cin >> a[i][j] >> t[i][j];
//			cout << "CCF\n";
			a[i][j]--;
			sta[a[i][j]][i] = t[i][j];
//			cout<<"CCF\n";
		}
//		cout<<"EEE\n";
	}
//	cout<<"q:"<<q<<endl;
	for (int i = 0;i < q;i++){
//		printf("cin plan,i:%d\n",i);
//		printf("rx[%d]:%d\n",i,rx[i]);
//		cout << "DDD\n";
//		int temp;
//		cin >> temp;
//		cout <<temp;
		
		cin >> rx[i];
		cin >> ry[i];
		rx[i]--;
		ry[i]--;
//		cout<<"CCC\n";////
		ans[i] = 0;
//		cout<<"BBB\n";
		ans[i] += w[rx[i]];ans[i] += w[ry[i]];
//		cout << "AAA\n";
	}
//	printf("finish cin\n");
	
	for (int i = 0;i < q;i++){
//		printf("search:%d %d\n",rx[i],ry[i]);
		ans[i] += search(rx[i],ry[i]);
	}
	
	for (int i = 0;i < q;i++){
		cout << ans[i] << "\n";
	}
	return 0;
}