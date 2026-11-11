#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
const int N = 2e5+10;

int id[200];
bool near[200][200];
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> b >> c >> d;
    id['A'] = id['B'] = id['C'] = 1;
    id['D'] = id['F'] = 2;
    near['A']['B'] = near['B']['C'] = near['D']['F'] = true;
    near['B']['A'] = near['C']['B'] = near['F']['D'] = true;   
    if (a == c){
        cout << "1";
        if (b[0] == d[0] && b[1] == d[1]){
            cout << "1";
            if (id[b[2]] == id[d[2]]){
                cout << "1";
                if (near[b[2]][d[2]]){
                    cout << "1";
                }
                else {
                    cout << "0";
                } 
                
            }
            else {
                cout << "00";
            }
        }
        else {
            cout << "000";
        }
    }
    else {
        cout << "0000";
    }


    return 0;
}