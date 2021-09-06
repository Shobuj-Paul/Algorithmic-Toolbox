# Uses python3
def edit_distance(s, t):
    #write your code here
    m, n = (len(s), len(t))
    D = [[0 for i in range(m+1)] for j in range(n+1)]
    for i in range(0,m+1):
        for j in range(0,n+1):
            if i==0:
                D[i][j] == j
            elif j==0:
                D[i][j] == i
            elif (s[i-1]==t[j-1]):
                D[i][j] = D[i-1][j-1]
            else:
                D[i][j] = 1 + min(D[i][j-1],D[i-1][j],D[i-1][j-1])
    return D[m][n]

if __name__ == "__main__":
    print(edit_distance(input(), input()))
