import requests
import bs4

# Get html response from website
# bs4 is a module for extracting information from an HTML page

BASE_URL = "http://www.algorist.com/"
COMP_FIN = 'computational_finance/'
COMP_BIO = 'computational_biology/'
ALGO     = ''

PDFS = list()
res = requests.get('http://www.cs.fsu.edu/~redwood/OffensiveComputerSecurity/')
try:
    res.raise_for_status()
except Exception as exc:
    print('There was a problem downloading the page {}'.format(exc))

algorist = bs4.BeautifulSoup(res.text, 'lxml')

links = algorist.select('a')
for link in links:
    print(link.get("href"))
    if 'pdf' in link.get('href'):
        full_url = BASE_URL + COMP_BIO + link.get('href')
        # print(link.get('href'))
        PDFS.append(full_url)
        print(full_url)
    # print(link)
