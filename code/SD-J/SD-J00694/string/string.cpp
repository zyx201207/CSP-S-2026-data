#include<bits/stdc++.h>

using namespace std;

int n;
bool ttt = true;
string sd;
long long dp[2000005],len,mid,fdt = 0,sum = 0,l = 0,r;
struct nsrt{
	long long a;
	char c;
};
nsrt po[200005];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 0;i<n;i++){
		cin >> po[i].a >> po[i].c;
	}
	//cout << sd << endl;
	//cout << checkhstr(sd);
	for(int i =1 ;i<n;i++){
		if(po[i-1].c != po[i].c){
			ttt = false;
		}
	}
	if(ttt){
		cout << 0;
		return 0;
	}
	/*///////////////////////////////
	for(int i = 0;i<n;i++){
		long long td = po[i].a;
		while(td--){
			sd += po[i].c;
		}
	}
	len = sd.size()-1;
	mid = len/2+1;
	fdt = 0;
	for(long long i = len;i>=mid;i--){
		//cout << sd[fdt] << " " << sd[i] << endl;
		if(sd[fdt] != sd[i]){
			sum++;
		}
		fdt++;
		//cout << sum << endl;
	}
	*/
	l = 0;
	r = n-1;
	sum = 0;
	while(l<r){
		//cout << 0 << " ///////////////" << endl;
		if(po[l].c != po[r].c){
			sum += min(po[l].a,po[r].a);
			long long t = min(po[l].a,po[r].a);
			//cout << min(po[l].a,po[r].a) << "min" << endl;
			po[l].a -= t;
			po[r].a -= t;
			//cout << l << " " << r << endl;
			//cout << po[l].a << " " << po[r].a << "des"<<endl;
		}
		else{
			long long t = min(po[l].a,po[r].a);
			po[l].a -= t;
			po[r].a -= t;
		}
		if(po[l].a == 0){
			l++;
		}
		if(po[r].a == 0){
			r--;
		}
		//cout << l << " " << r << endl;
		//cout << po[l].a << " " << po[r].a << "dfsa" <<endl;
		//cout << sum << "sum" << endl;
	}
	cout << sum << endl;
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
