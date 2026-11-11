#include <iostread>
using namespace std;
int main(){
//许皓尘 SN-J00826 西安市碑林区第十二中学 
//freopen("card.in","r",stdin);
//freopen("card,out","w",stdout);
    int s[11000],ans;
    int n,m;
    cin >> n >> m; 
    for (int i = 1; i <= n;i++)cin >> s[i];{
    int t = m+1;
    while(t <= n+m){
    	for (int i = 1;i <= m;i++);{
    	s[i]--;
    	if(s[i]==0)
	       s[i] = s[t];
	       t++;
           }
		}
		ans ++;
	}
	cout << ans;
	return 0;      	
}

