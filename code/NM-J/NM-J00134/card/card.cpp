#include <bits/stdc++.h>
using namespace std;

int a[500005];
int b[300005];
int c[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    string s;
    for(int i = 0;i < n;i++){
    	cin >> b[i];
	}

    for(int i = 0;i < n;i++){
        for(int j = i;j < n;j++){
            s += b[j];
            if(c[b[j]] == 1){
            	for(int z = 0;z < j;z++){
            		c[s[z]]= 0;
            		s[z] = 0;
				}
			}
			c[b[j]] = 1;
        }

        for(int z = 0;z < s.size();z++){
        	c[s[z]] = 1;
		}

        for(int z = 0;z <= m;z++){
            if(c[z] == 1){
                a[z]++;
            }
            c[z] = 0;
        }
        s = "";
    }

    for(int i = 1;i <= m;i++){
        cout << a[i] << " ";
    }
    return 0;
}
