#include <bits/stdc++.h>
using namespace std;
int a[500005];
int number[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    int i=1;
    while (i<n){
        vector <int> b;
        b.clear();
        b.push_back(0);
        for (int j=i;j<=n;j++){
            for (int z=0;z<b.size();z++){
                if (b[z]==a[j]){
                        //cout << 100 << endl;
                    for (int c=z;c<b.size();c++){
                        b[c]=0;
                    }
                    break;
                }
            }
            b.push_back(a[j]);
        }

        for (int k=0;k<b.size();k++){
                //cout << 100 << endl;

            for (int h=1;h<=m;h++){
                if (b[k]==h){
                    number[h]++;
                    //cout << 100 << endl;
                }
            }
        }

        i++;
        //cout << 100 << endl;
    }
    number[a[n]]++;
    //cout << 100 << endl;
    for (int j=1;j<=m;j++){
        cout << number[j] << " ";
    }
    //cout << 1 << " ";
    return 0;
}

