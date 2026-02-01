# AGENTS.md

## Project Overview

**In Finite Data** is the online component of a sound performance piece that uses audience input as source material. Audiences see a random image with a text prompt, record a voice message via SpeakPipe, and the audio is used in live performance.

Originally derived from ∞±∞ (early 2000s). This version performed at SDNOW conference, Melbourne 2019.

## Architecture & Structure

```
├── index.html      # Main audience-facing page (random image + prompt + SpeakPipe embed)
├── ingest.html     # Ingestion/collection interface
├── images/         # Image set shown randomly to audience
└── README.md       # Documentation and history
```

Purely static HTML — no build process, no dependencies beyond SpeakPipe embed.

## Setup & Commands

```bash
# Any static server, or open directly
python -m http.server
```

## Conventions

- Vanilla HTML/JS — no frameworks
- Images in `images/` are the random pool shown to participants
- SpeakPipe integration for audio recording
- This is a performance piece — the simplicity is intentional

## What NOT to Do

- Don't overcomplicate with frameworks — the rawness is part of the aesthetic
- Don't remove or restructure the image set without understanding the performance context
- Don't break SpeakPipe integration
